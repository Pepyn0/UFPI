import socket

host = 'localhost'
port = 8000
addr  = (host, port)

servSocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
servSocket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
servSocket.bind(addr)
servSocket.listen(2)

print("Aguardado conexão...")
conexao, cliente = servSocket.accept()
print("Conectado")
print("Aguardando mensagem...")

enviar = ''
while(enviar != 'exit'):
	recebe = conexao.recv(1024)
	print("Cliente({}): ".format(cliente) + recebe.decode())
	enviar = input("Digite uma mensagem para enviar ao cliente: ")
	conexao.send(enviar.encode())

servSocket.close()
