#include <stdio.h>
#include <stdlib.h>

void change_proxy_syswide(const char* proxy)
{
    char command1[1024], command2[1024], command3[1024], command4[1024], command5[1024];
    sprintf(command1, "echo 'Acquire::http::proxy \"%s\";' > /etc/apt/apt.conf", proxy);
    sprintf(command5, "echo '%s' > /home/zerone/launch_chrome.zttf", proxy); //fallback for chrome if browser does not picks up the proxy
    sprintf(command2, "export http_proxy=http://'%s'", proxy);
    sprintf(command3, "export https_proxy=http://'%s'", proxy);
    sprintf(command4, "export ftp_proxy=http://'%s'", proxy);
    system(command1);
    system(command2);
    system(command3);
    system(command4);
    printf("Done!\n");
}

void disp_loop_main()
{
    char comm_proxy[256];
    printf("Enter the custom proxy address: ");
    scanf("%s", comm_proxy);
    printf("\nSetting the proxy address to: %s\n", comm_proxy);
    change_proxy_syswide(comm_proxy);
}

int main()
{
    int i = 1;
    while (i == 1)
        disp_loop_main();
    return 0;
}

