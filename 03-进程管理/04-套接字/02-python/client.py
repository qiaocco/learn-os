import socket  # 导入 socket 模块

host = "127.0.0.1"  # 获取本地主机名
port = 12345  # 设置端口号


def main():
    s = socket.socket()  # 创建 socket 对象

    s.connect((host, port))
    s.sendall("hello, I am client".encode())
    print(s.recv(1024).decode())

    s.close()


if __name__ == '__main__':
    main()
