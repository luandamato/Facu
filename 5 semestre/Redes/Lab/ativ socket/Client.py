import socket
import select
import errno

header_tam = 10
ip = "192.168.0.13"
porta = 31817

my_username = input("Username: ")

client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client_socket.connect((ip, porta))
client_socket.setblocking(False)

username = my_username.encode('utf-8')
username_header = f"{len(username):<{header_tam}}".encode('utf-8')

client_socket.send(username_header + username)


while True:
    #mensagem = input(f"{my_username} >")
    mensagem = ""

    if mensagem:
        mensagem = mensagem.encode('utf-8')
        mensagem_header = f"{len(mensagem) :< {header_tam}}".encode('utf-8')
        client_socket.send(mensagem_header + mensagem)

    try:
        while True:
            username_header = client_socket.recv(header_tam)
            if not len(username_header):
                print("Conexão com servidor fechada")
                #sys.exit()
            username_tam = int(username_tam.decode('utf-8').strip())
            username = client_socket.recv(username_tam).decode('utf-8')

            mensagem_header = client_socket.recv(header_tam)
            mensagem_tam = int(mensagem_header.decode('utf-8').strip())
            mensagem = client_socket.recv(mensagem_tam).decode('utf-8')

            print(f"{username} > {mensagem}")

    except IOError as e:
        if e.errno != errno.EAGAIN and e.errno != errno.EWOULDBLOCK:
            print("Erro", str(e))
        
        continue
    except Exception as e:
        print("Erro", str(e))
        pass

