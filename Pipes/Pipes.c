#include<stdio.h>
#include<unistd.h>

int main() {
   int pipefds1[2], pipefds2[2];
   int returnstatus1, returnstatus2;
   int pid;
   char pipe1writemessage[20] = "Enkokelesh";
   char pipe2writemessage[20] = "Menawekeleh";
   char readmessage[20];
   
   if (pipe(pipefds1) == -1) {
      printf("Unable to create pipe 1 \n");
      return 1;
   }
   
   if (pipe(pipefds2) == -1) {
      printf("Unable to create pipe 2 \n");
      return 1;
   }
   pid = fork();
   
   for (int i = 0; i < 3; i++){

      if (pid != 0){ // Parent process {
         close(pipefds1[0]); // Close the unwantead pipe1 read side
         close(pipefds2[1]); // Close the unwanted pipe2 write side
         printf("In Parent: Writing to pipe 1 -%s\n", pipe1writemessage);
         write(pipefds1[1], pipe1writemessage, sizeof(pipe1writemessage));
         read(pipefds2[0], readmessage, sizeof(readmessage));
         printf("In Parent: Reading from pipe 2 –  %s\n", readmessage);
      } else { //child process
         close(pipefds1[1]); // Close the unwanted pipe1 write side
         close(pipefds2[0]); // Close the unwanted pipe2 read side
         read(pipefds1[0], readmessage, sizeof(readmessage));
         printf("In Child: Reading from pipe 1 –  %s\n", readmessage);
         printf("In Child: Writing to pipe 2 –  %s\n", pipe2writemessage);
         write(pipefds2[1], pipe2writemessage, sizeof(pipe2writemessage));
      }
   }
   
   return 0;
}