import socket


def client():

    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client_socket.connect((socket.gethostname(), 12345))

    message = "hbennn12123"
    print("received from server: " + client_socket.recv(1024).decode())

    client_socket.send(message.encode())

# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    client()

# See PyCharm help at https://www.jetbrains.com/help/pycharm/































