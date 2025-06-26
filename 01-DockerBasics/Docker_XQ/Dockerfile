FROM ubuntu:22.04

# Éviter les interactions pendant l'installation
ENV DEBIAN_FRONTEND=noninteractive

# Installer un environnement de bureau léger (XFCE) et les outils essentiels
RUN apt-get update && apt-get install -y \
    xfce4 \
    xfce4-terminal \
    dbus-x11 \
    xauth \
    x11-xserver-utils \
    firefox \
    build-essential \
    cmake \
    g++ \
    git \
    make \
    pkg-config \
    libncurses-dev \
    libsdl2-dev \
    libsfml-dev \
    sudo \
    nano \
    wget \
    curl \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

# Créer un utilisateur non-root
RUN useradd -m developer && \
    echo "developer:password" | chpasswd && \
    usermod -aG sudo developer

# Configurer le répertoire de travail
WORKDIR /home/developer

# Donner la propriété au nouvel utilisateur
RUN chown -R developer:developer /home/developer

# Définir les variables d'environnement pour X11
ENV DISPLAY=host.docker.internal:0

# Utiliser l'utilisateur non-root
USER developer

# Démarrer l'environnement de bureau XFCE
CMD ["startxfce4"]