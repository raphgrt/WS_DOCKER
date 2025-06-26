# FROM ubuntu:mantic

# Sur une plateforme différente :
FROM --platform=linux/amd64 ubuntu:latest

# Installer les outils de compilation nécessaires
RUN apt-get update && apt-get install -y \
    build-essential \
    libncurses-dev \
    make \
    gcc

# Définir le répertoire de travail
WORKDIR /app

# Copier le code source de l'application
COPY . /app

# Utiliser un shell pour exécuter plusieurs commandes
CMD ["/bin/bash"]