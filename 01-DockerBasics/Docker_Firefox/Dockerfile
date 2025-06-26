FROM ubuntu:22.04

# Éviter les interactions pendant l'installation
ENV DEBIAN_FRONTEND=noninteractive

# Installer les outils nécessaires pour ajouter un PPA
RUN apt-get update && apt-get install -y \
    software-properties-common \
    apt-transport-https \
    wget \
    gnupg \
    && apt-get clean

# Ajouter le PPA de Mozilla pour Firefox
RUN add-apt-repository ppa:mozillateam/ppa -y && \
    echo 'Package: *\nPin: release o=LP-PPA-mozillateam\nPin-Priority: 1001' > /etc/apt/preferences.d/mozilla-firefox

# Installer Firefox et les dépendances X11
RUN apt-get update && apt-get install -y \
    firefox \
    dbus-x11 \
    xauth \
    libcanberra-gtk-module \
    libcanberra-gtk3-module \
    pulseaudio \
    ca-certificates \
    --no-install-recommends \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

# Créer un utilisateur non-root
RUN useradd -m firefox-user && \
    mkdir -p /home/firefox-user/.mozilla

# Définir le répertoire de travail
WORKDIR /home/firefox-user

# Donner la propriété à l'utilisateur
RUN chown -R firefox-user:firefox-user /home/firefox-user

# Utiliser l'utilisateur non-root
USER firefox-user

# Configurer l'affichage X11
ENV DISPLAY=host.docker.internal:0

# Exécuter Firefox
CMD ["firefox", "--no-sandbox"]