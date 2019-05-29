#include <iostream>

// fork
#include <unistd.h>
#include <sys/types.h>

// wait
#include <wait.h>

int main() {
    std::cout << "I am parent" << std::endl;
    pid_t pid = fork();

    if (pid == 0) {  // child
        int r = execve("./child", NULL, NULL);
    }
    else {  // parent
        int status = 0;
        waitpid(pid, &status, 0);
    }
    return 0;
}