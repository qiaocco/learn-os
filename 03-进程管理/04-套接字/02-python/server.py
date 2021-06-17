import socket  # 导入 socket 模块


# 参考文章： https://www.liujiangblog.com/course/python/76

def main():
    # socket.AF_INET    用于服务器之间网络通信
    # socket.SOCK_STREAM    基于TCP的流式socket通信
    serversocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)  # 创建 socket 对象
    host = socket.gethostname()  # 获取本地主机名
    port = 12345  # 设置端口
    serversocket.bind((host, port))  # 绑定端口

    serversocket.listen(5)  # 监听端口，等待客户端连接

    while True:
        conn, addr = serversocket.accept()  # 建立客户端连接
        print('连接地址：', addr)
        conn.send('hello qiaocc'.encode())
        conn.close()  # 关闭连接


if __name__ == '__main__':
    main()
