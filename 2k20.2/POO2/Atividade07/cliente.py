import socket

ip = 'localhost'
port = 8000
addr = ((ip, port))
clientSocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
clientSocket.connect(addr)

mensagem = dado = ''
while(mensagem != 'exit' and dado != 'exit'):
	mensagem = input("Digite uma mensagem para enviar ao servidor: ")
	clientSocket.send(mensagem.encode())
	#print("Mensagem enviada")
	dado = clientSocket.recv(1024).decode()
	if(mensagem != 'exit' and dado != 'exit'):
		print("Servidor: " + dado)

clientSocket.close()
