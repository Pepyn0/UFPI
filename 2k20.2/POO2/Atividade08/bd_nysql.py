import mysql.connector as mysql

conexao = mysql.connect(host = 'localhost', db = 'teste', user = 'root', passwd = 'toor')
cursor = conexao.cursor()

sql = """CREATE TABLE IF NOT EXISTS usuarios(
			id integer AUTO_INCREMENT PRIMARY KEY,
			nome text NOT NULL,
			email text NOT NULL
		);"""

nome = 'user01'
email = 'user01@emal.com'

cursor.execute(sql)

for i in range(5):
	cursor.execute('INSERT INTO usuarios(nome, email) VALUES (%s,%s)', (nome, email))

cursor.execute('SELECT * FROM usuarios')

for c in cursor:
	print(c)

conexao.commit()
conexao.close()
