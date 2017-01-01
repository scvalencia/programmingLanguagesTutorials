/*******************************
Project Name:   SlowPrint
Programmer:     Niels uit de Bos
Date:           July 14, 2005

SlowPrint, the function this program's about, can be used as a replacement
for the standard printf() function. The difference between SlowPrint and
printf is SlowPrint doesn't put the information on the screen immediatly, but
smoothly letter after letter. 
******************************/

#include <stdio.h>

/* Input: a string & the amount of mm seconds to wait between every
letter */
void SlowPrint(char* string, int sleeptime) 
{
     int i = 0;
     while(string[i] != '\0')    
     {       
             printf("%c", string[i]);
             Sleep(sleeptime);
             i++;
     }
}

int main() // just a little example
{
    SlowPrint("Hi! You're looking at an example of the slowprint function!", 50);
    Sleep(2000);
    
    return 0;
}       
