import socket  # 导入 socket 模块

# 参考文章： https://www.liujiangblog.com/course/python/76

host = "127.0.0.1"
port = 12345  # 设置端口


def main():
    # socket.AF_INET    用于服务器之间网络通信
    # socket.SOCK_STREAM    基于TCP的流式socket通信
    serversocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)  # 创建 socket 对象
    # 设置端口可复用，保证我们每次Ctrl C之后，快速再次重启
    serversocket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)

    serversocket.bind((host, port))  # 绑定端口
    serversocket.listen(5)  # 监听端口，等待客户端连接

    while True:
        conn, addr = serversocket.accept()  # 建立客户端连接
        print('连接地址：', addr)
        data = conn.recv(1024)
        print("收到客户端数据:", data.decode())
        if not data:
            break
        conn.send('hello qiaocc'.encode())
        conn.close()  # 关闭连接


if __name__ == '__main__':
    main()
