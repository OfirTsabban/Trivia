import socket


def client():
    option = "0"
    while option != "2" and option != "1":
        option = input("1 - login, 2 - signup:\n")

    if option == "1":
        username = input("Enter username: ")
        password = input("Enter password: ")
        json = '{username: "' + username + '", password:"' + password + '"}'
        code_encoded = option.encode()

    elif option == "2":
        username = input("Enter username: ")
        password = input("Enter password: ")
        email = input("Enter email: ")
        json = '{username: "' + username + '", password: "' + password + '", mail: "' + email + '"}'
        code_encoded = option.encode()

    print("Json that has been created" + json)

    msg_to_send = code_encoded + str(len(json)).encode() + json.encode()

    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client_socket.connect((socket.gethostname(), 12345))

    message = "hbennn12123"
    print("received from server: " + client_socket.recv(1024).decode())

    client_socket.send(message.encode())


# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    client()

# See PyCharm help at https://www.jetbrains.com/help/pycharm/
