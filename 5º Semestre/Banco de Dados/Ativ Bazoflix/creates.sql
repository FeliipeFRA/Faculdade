CREATE TABLE plano (
	id INT AUTO_INCREMENT PRIMARY KEY,
    nome varchar(20),
    valor double,
    num_telas int
);

CREATE TABLE usuario (
	id INT AUTO_INCREMENT PRIMARY KEY,
    plano_usuario INT,
    email varchar(50),
    nome varchar(100),
    password varchar(100),
    cep varchar(8),
    data_renov date,
    status_plano bool,
    FOREIGN KEY (plano_usuario) REFERENCES plano(id)
);

CREATE TABLE filme (
	id INT AUTO_INCREMENT PRIMARY KEY,
    titulo varchar(50),
    genero varchar(20),
    data_lanc date,
    elenco varchar(200),
    rating int
);

CREATE TABLE filmes_assistidos (
	id INT AUTO_INCREMENT PRIMARY KEY,
	id_usuario INT,
    id_filme INT,
    data_reproducao DATETIME,
	FOREIGN KEY (id_usuario) REFERENCES usuario(id),
    FOREIGN KEY (id_filme) REFERENCES filme(id)
);

CREATE TABLE comentario (
	id INT AUTO_INCREMENT PRIMARY KEY,
    id_usuario INT,
    id_filme INT,
    data_comentario DATETIME,
    texto varchar(500),
    FOREIGN KEY (id_usuario) REFERENCES usuario(id),
    FOREIGN KEY (id_filme) REFERENCES filme(id)
);
 
 CREATE TABLE listas (
	id INT AUTO_INCREMENT PRIMARY KEY,
    nome varchar(100),
    id_usuario INT,
    FOREIGN KEY (id_usuario) REFERENCES usuario(id)
);

CREATE TABLE filmes_lista (
	id_filmes_lista INT AUTO_INCREMENT PRIMARY KEY,
    id_lista INT,
    id_flime INT,
    FOREIGN KEY (id_lista) REFERENCES lista(id),
    FOREIGN KEY (id_filme) REFERENCES filme(id)
);

CREATE TABLE pagamento (
	id INT AUTO_INCREMENT PRIMARY KEY,
    valor DOUBLE,
    id_usuario INT,
    id_plano INT,
    data_pag DATETIME,
    status varchar(15),
    FOREIGN KEY (id_usuario) REFERENCES usuario(id),
    FOREIGN KEY (id_plano) REFERENCES plano(id)
);