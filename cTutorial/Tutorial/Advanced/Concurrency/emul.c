/* Copyright (c) 2000 Jonathan A. Rees */

#define DEFAULT_TTY "/dev/ttyS0"
#define ESCAPE_CHAR 29		/* control-] */
#define STDIN 0
#define STDOUT 1
#define STDIO STDIN

#include <stdio.h>

/* #include <sys/ioctl.h> */
#include <termios.h>

/* These three are for open(2) */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/* For fork(2) */

#include <unistd.h>

/* ---------------------------------------------------------------------- */

void main(int argc, char **argv) {

  int fd;
  pid_t pid;
  char *ttyname = DEFAULT_TTY;
  struct termios serial_before;
  struct termios serial_modified;
  struct termios stdio_before;
  struct termios stdio_modified;

  if (argc > 1)
    ttyname = argv[1];

  fd = open(ttyname, O_RDWR);
  if (fd < 0) {			/* Open failed */
    perror(argv[0]);
    exit(1);
  }

  fprintf(stderr, "` Opened %s\n", ttyname);

  fprintf(stderr, "` Setting serial line to raw mode\n");
  if (tcgetattr(fd, &serial_before) < 0) {
    perror(argv[0]); exit(1); }
  serial_modified = serial_before;
  cfmakeraw (&serial_modified);
  if (tcsetattr (fd, TCSADRAIN, &serial_modified) < 0) {
    perror(argv[0]); exit(1); }

  fprintf(stderr, "` Setting stdin/stdout to raw mode\n");
  if (tcgetattr(STDIO, &stdio_before) < 0) {
    perror(argv[0]); exit(1); }
  stdio_modified = stdio_before;
  cfmakeraw (&stdio_modified);
  if (tcsetattr (STDIO, TCSADRAIN, &stdio_modified) < 0) {
    perror(argv[0]); exit(1); }

  pid = fork();
  if (pid < 0) {		/* Fork failed */
    perror(argv[0]); exit(1); }

  if (pid > 0) {		/* Original (parent) thread */
    int lost = 0;

    fprintf(stderr,
	    "` Escape character is control-%c\r\n",
	    ESCAPE_CHAR + 64);

    {
      char buf[1];
      ssize_t count;

      /* Copy characters from stdin to the serial line */
      while(1) {
	count = read(STDIN, &buf[0], (size_t) 1);
	if (count < 0) {
	  perror(argv[0]);
	  break; }
	if (count == 0) {
	  fprintf(stderr, "` ?zero read count?\r\n");
	  continue; }
	if (buf[0] == ESCAPE_CHAR)
	  break;
	if (write(fd, &buf[0], count) < 0) {
	  perror(argv[0]);
	  break; }
      }}

    fprintf(stderr, "` Killing child thread\r\n");
    if (kill(pid, 9) < 0) {
      perror(argv[0]); lost = 1; }

    fprintf(stderr, "` Resetting standard I/O modes\r\n");
    if (tcsetattr (STDIO, TCSADRAIN, &stdio_before) < 0) {
      perror(argv[0]); lost = 1; }

    fprintf(stderr, "` Resetting serial line modes\r\n");
    if (tcsetattr (fd, TCSADRAIN, &serial_before) < 0) {
      perror(argv[0]); lost = 1; }

    /* BUG -- SHOULD WAIT FOR CHILD */

    exit(lost);

  } else /* pid == 0 */ {	/* Spawned (child) thread */
    /* fprintf(stderr, "` (Child thread)\r\n"); */

    {
      char buf[1];
      ssize_t count;

      /* Copy characters from serial line to stdout  */
      while(1) {
	count = read(fd, &buf[0], (size_t) 1);
	if (count < 0) {
	  perror(argv[0]);
	  break; }
	if (count == 0) {
	  fprintf(stderr, "` (?zero read count?)\r\n");
	  continue; }
	if (write(STDOUT, &buf[0], count) < 0) {
	  perror(argv[0]);
	  break; }
      }}
    exit(0);
  }
}
