import socket  #importa modulo socket
  
IP_destino = "192.168.0.13"  #Endereço IP do servidor
PORTA_destino = 5005          #Numero de porta do servidor

#Criação de socket UDP
sock = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
    
#sock.bind((IP_servidor, PORTA_destino)) 
while True:
    MENSAGEM = input("enviar: ")
    print ("Mensagem enviada:", MENSAGEM)
    
    #Envia mensagem usando socket UDP
    sock.sendto(MENSAGEM.encode('UTF-8'), (IP_destino, PORTA_destino))

    data, addr = sock.recvfrom(1024)
    print ("Mensagem recebida:", data)

