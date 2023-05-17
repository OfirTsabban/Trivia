import socket


def client():
    option = "0"
    while option != "2" and option != "1":
        option = input("1 - login, 2 - signup:\n")

    if option == "1":
        username = input("Enter username: ")
        password = input("Enter password: ")
        json = '{"username": "' + username + '", "password":"' + password + '"}'
        msg_code_encoded = option.encode()

    elif option == "2":
        username = input("Enter username: ")
        password = input("Enter password: ")
        email = input("Enter email: ")
        street = input("Enter street: ")
        apt = input("Enter apartment: ")
        city = input("Enter city: ")
        prefix = input("Enter prefix: ")
        number = input("Enter number: ")
        yearBorn = input("Enter birth year: ")
        json = '{"username": "' + username + '", "password": "' + password + '", "mail": "' + email + '", "street": "' + street + '", "apt": ' + apt + ', "city": "' + city + '", "prefix": "' + prefix + '", "number": "' + number + '", "yearBorn": "' + yearBorn + '"}'
        msg_code_encoded = option.encode()

    print("Json that has been created: " + json)

    message = msg_code_encoded + str(len(json)).encode() + json.encode()
    message = message.decode().replace("'", '"').encode()
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client_socket.connect((socket.gethostname(), 12345))

    client_socket.send(message)

    print("received from server: " + client_socket.recv(1024).decode())


# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    client()

# See PyCharm help at https://www.jetbrains.com/help/pycharm/
