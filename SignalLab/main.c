void main(void) {
    pid_t pid;
    int num;
}

for(num = 0; num < 2; num++) {
    pid = fork();
    if (pid == 0){
        childProcess(num);
    else if (pid < 0){
        printf("error in the fork\n");
    }
    parentProcess();
    }
}

void childProcess(int myid) {
    int i;
    int random_n;
    int random_m;

    random_m = rand() % 2 + 1;
    for(i = 0; i < random_m; i++) {
        printf("Child Pid: %d is going to sleep now!\n", getpid());

        srand(getpid());

        random_n = rand() % 10;

        sleep(random_n + 1);
        printf("Child Pid: is awake now!\n Where is my parent: %d\n", getpid());
    }
    exit(0);
}

void parentProcess(void) {
    int num;
    int pid;
    int status;

    for(num = 0; num < 2;  num++) {
        pid = wait(&status);
        printf("Child Pid: %d has completed \n", pid);
    }
}