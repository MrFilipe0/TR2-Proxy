# TR2-Proxy

Alunos:
André Filipe de Sousa Silva - 16/0079926
Evandro Thalles Vale de Castro - 16/0119286


Para executar o programa é necessário, primeiramente rodar o comando qmake, comando esse no qual irá gerar todas as dependencias necessarias para o uso da interface grafica QT creator, após isso mover todos os arquivos presentes nas pastas "lib", "src" e "qt" para pasta raiz do projeto.Após isso pode-se, então executar o comando make no terminal aberto nesta mesma pasta. Será gerado um arquivo executável "aracne", basta digitar "./aracne -p porta" ou "./aracne", onde "porta" é a porta TCP em que se deseja conectar o servidor proxy. Caso não seja fornecida uma porta, como espeficado no projeto, será utilizada a porta 8228 como padrão.

Obs: É necessário ter o Qt Creator instalado para compilar o código.