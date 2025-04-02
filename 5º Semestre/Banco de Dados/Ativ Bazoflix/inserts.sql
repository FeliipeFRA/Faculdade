-- Planos
INSERT INTO plano (nome, valor, num_telas) VALUES 
('Básico', 19.90, 1), 
('Padrão', 29.90, 2), 
('Premium', 39.90, 4);

-- Usuários
INSERT INTO usuario (plano_usuario, email, nome, password, cep, data_renov, status_plano) VALUES 
(1, 'eliza@mail.com', 'Eliza Bomfim', 'senha123', '12345678', '2025-04-01', 1),
(2, 'carlos@mail.com', 'Carlos Silva', 'senha456', '87654321', '2025-03-15', 1),
(3, 'ana@mail.com', 'Ana Souza', 'senha789', '11223344', '2025-03-20', 1);

-- Filmes
INSERT INTO filme (titulo, genero, data_lanc, elenco, rating) VALUES 
('A Origem', 'suspense', '2010-07-16', 'Leonardo DiCaprio, Ellen Page', 9),
('Coringa', 'drama', '2019-10-04', 'Joaquin Phoenix, Robert De Niro', 8),
('O Chamado', 'terror', '2002-10-18', 'Naomi Watts, Martin Henderson', 7),
('Seven', 'suspense', '1995-09-22', 'Brad Pitt, Morgan Freeman', 9);

-- Filmes Assistidos
INSERT INTO filmes_assistidos (id_usuario, id_filme, data_reproducao) VALUES 
(1, 1, '2025-03-25 20:00:00'),
(1, 2, '2025-03-26 21:00:00'),
(2, 1, '2025-03-27 22:00:00'),
(3, 3, '2025-03-28 19:00:00');

-- Comentários
INSERT INTO comentario (id_usuario, id_filme, data_comentario, texto) VALUES 
(1, 1, '2025-03-25 21:00:00', 'Ótimo filme!'),
(2, 2, '2025-03-26 22:00:00', 'Incrível interpretação!'),
(3, 3, '2025-03-28 20:00:00', 'Assustador demais!');

-- Pagamentos
INSERT INTO pagamento (valor, id_usuario, id_plano, data_pag, status) VALUES 
(19.90, 1, 1, '2025-03-10 15:00:00', 'pago'),
(29.90, 2, 2, '2025-03-12 16:00:00', 'pago');

-- Listas
INSERT INTO listas (nome, id_usuario) VALUES 
('Favoritos', 1), 
('Para Assistir', 2);
