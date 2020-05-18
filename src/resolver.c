#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <regex.h>

void SolveMaze(char *maze, int width, int height) {

    int dir, count;
    int x, y;
    int dx, dy;
    int forward;

    /* Remove the entry and exit. */
   maze[0 * width + 1] = 1;
   maze[(height - 1) * width + (width - 2)] = 1;

   forward = 1;
   dir = 0;
   count = 0;
   x = 1;
   y = 1;
   while(x != width - 2 || y != height - 2) {
      dx = 0; dy = 0;
      switch(dir) {
      case 0:  dx = 1;  break;
      case 1:  dy = 1;  break;
      case 2:  dx = -1; break;
      default: dy = -1; break;
      }
      if(   (forward  && maze[(y + dy) * width + (x + dx)] == 0)
         || (!forward && maze[(y + dy) * width + (x + dx)] == 2)) {
         maze[y * width + x] = forward ? 2 : 3;
         x += dx;
         y += dy;
         forward = 1;
         count = 0;
         dir = 0;
      } else {
         dir = (dir + 1) % 4;
         count += 1;
         if(count > 3) {
            forward = 0;
            count = 0;
         }
      }
   }

   /* Replace the entry and exit. */
   maze[(height - 2) * width + (width - 2)] = 2;
   maze[(height - 1) * width + (width - 2)] = 2;

}

int main(int argc, char *argv[]) {

    int width, height;
    char *maze;

    /* Open file */
    FILE *fp = fopen(argv[1] , "r");

    /* Get maze width and height */
    
    height = 0;
    width = fp.regex();
    
    if(!width || !height){
        printf("error: illegal size /n");
        exit(EXIT_FAILURE);
    }

    /* Get maze */
    maze = (char*)"";
    if(maze == NULL) {
        printf("error: maze not found");
        exit(EXIT_FAILURE);
    }

    /* Solve maze */
    SolveMaze(maze, width, height);


    /* Clean up. */
    fclose(fp); 
    free(maze);
    free(width);
    free(height);
    exit(EXIT_SUCCESS);
}