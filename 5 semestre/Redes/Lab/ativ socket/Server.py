import socket
import select

header_tam = 10
ip = "192.168.0.13"
porta = 13000

server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)

server_socket.bind((ip, porta))
server_socket.listen()

lista_sockets = [server_socket]
clientes = {}


def receber_mensagem(client):
    try:
        mensagem_header = client.recv(header_tam)
        if not len(mensagem_header):
                return False
        mensagem_tam = int(mensagem_header.decode("utf-8").strip())
        return {"header": mensagem_header, "data": client.recv(mensagem_tam)}

    except:
        return False

while True:
    read_sockets, _, exceptions = select.select(lista_sockets, [], lista_sockets)
    for notificacao in read_sockets:
        if notificacao == server_socket:
            cliente_socket, cliente_endereco = server_socket.accept()
            user = receber_mensagem(cliente_socket)
            if user is False:
                continue

            lista_sockets.append(cliente_socket)
            clientes[cliente_socket] = user
            print(f"Nova conexão de {cliente_endereco[0]}:{cliente_endereco[1]} username: {user['data'].decode('utf-8')}")

        else:
            mensagem = receber_mensagem(notificacao)

            if mensagem is False:
                print(f"conexão fechada de {clientes[notificacao]['data'].decode('utf-8')}")
                lista_sockets.remove(notificacao)
                del clientes[notificacao]
                continue

            user = clientes[notificacao]
            print(f"Mensagem recebida de {user['data'].decode('utf-8')}: {mensagem['data'].decode(['utf-8'])}")

            for cliente_socket in clientes:
                if cliente_socket != notificacao:
                    cliente_socket.send(user['header'] + user['data'] + mensagem['header'] + mensagem['data'])

        for notificacao in exceptions:
            lista_sockets.remove(notificacao)
            del clientes[notificacao]
