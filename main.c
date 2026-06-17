#include <stdio.h>
#include <dirent.h>

int listdir(const char *path) 
{
  struct dirent *entry;
  DIR *dp;

  dp = opendir(path);
  if (dp == NULL) 
  {
    perror("opendir");
    return -1;
  }

  while((entry = readdir(dp)))
    puts(entry->d_name);

  closedir(dp);
  return 0;
}

int main(int argc, char **argv) {

  if (argc == 1)
	listdir(".");

  for (int i = 1; i < argc; i++) {
      printf("\nListing %s...\n", argv[i]);
      listdir(argv[i]);
  }

  return 0;
}