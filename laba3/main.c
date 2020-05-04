#include <dirent.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <dlfcn.h>

int main(){
	void *handle;
 	char *error;
	char name[30];
	printf("Enter name(Example: /home/ur/hello/File1.txt): ");
	scanf("%s",name);
	handle = dlopen("/home/ur/hello/func.so", RTLD_LAZY);
	if (!handle) {
		fprintf(stderr, "%s\n", dlerror());
		return 0;
	}
	
	dlerror();
	void(*func)(char[]) = dlsym(handle,"func");

	if ((error = dlerror()) != NULL) {
 		fprintf(stderr, "%s\n", error);
 		return 0;
	}
	func(name);
        dlclose(handle);
        return 0;
}

