//make FSMidentifier && ./FSMidentifier

#include <stdio.h>
#include <ctype.h>
#include <string.h>

typedef enum {
	start,
	stop,
	build_id,
	build_num,
	number,
	identifier
} state;

state transition(state current, char transition);
void print_state(state current_state);


int main(void) {
	state current_state = start;
	char transition_char;
	while(current_state != stop) {
		if(current_state == identifier) {
			printf(" - Identifier\n");
			current_state = start;
		}
		else if(current_state == number) {
			printf(" - Number\n");
			current_state = start;
		}		
		scanf("%c", &transition_char);
		if(transition_char != '\n')
			printf("%c", transition_char);		
		current_state = transition(current_state, transition_char);
		

	}
	
	return 0;
}

state transition(state current, char transition) {
	
	if(current == start) {
		if(isdigit(transition))
			return build_num;
		else if(isalpha(transition))
			return build_id;
		else if(transition == '.')
			return stop;
		else if(transition == '\n')
			return start;
	}
	else if(current == build_num) {
		if(transition == '\n')
			return number;
		else if(isdigit(transition))
			return build_num;
	}
	else if(current == build_id) {
		if(isalpha(transition))
			return build_id;
		else if(isdigit(transition))
			return build_id;
		else if(transition == '_')
			return build_id;
		else if(transition == '\n')
			return identifier;

	}
	
	return stop;
}

void print_state(state current_state) {

	if(current_state == start)
		printf("Start\n");
	else if(current_state == stop)
		printf("Stop\n");
	else if(current_state == build_id)
		printf("Build_id\n");
	else if(current_state == build_num)
		printf("Build_num\n");
	else if(current_state == number)
		printf("Number\n");
	else
		printf("Identifier\n");

}

