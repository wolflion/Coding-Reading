//在绑定前设置端口复用

int flag = 1;
setsockopt(lfd, SOL_SOCKET, SO_REUSEADDR, &flag, sizeof(flag));

int ret = bind(lfd, (struct sockaddr*)&server, sizeof(server));