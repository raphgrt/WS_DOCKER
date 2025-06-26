# MacOS et Docker

## Introduction

Le développement sur MacOS peut présenter des défis uniques, particulièrement depuis l'introduction des processeurs Apple Silicon (ARM). Comment assurer que notre code fonctionne sur différentes architectures et systèmes d'exploitation? Docker apporte des solutions élégantes à ces problématiques.

Cette présentation explore trois approches pour utiliser Docker sur MacOS:
- Compilation cross-architecture simple
- Multi-architecture avec Buildx
- Environnements de développement avec Dev Containers

## 1. Docker pour la compilation cross-architecture

### Problématique
Comment compiler du code sur MacOS ARM pour qu'il fonctionne sur Fedora x86?

### Solution
Utiliser Docker pour créer un environnement d'exécution Fedora x86:

```bash
# Création d'un simple Dockerfile pour Fedora
cat > Dockerfile <<EOF
FROM fedora:latest

# Installation des outils de développement
RUN dnf update -y && dnf install -y \
    gcc \
    make \
    glibc-devel

WORKDIR /app
EOF

# Construction de l'image
docker build -t fedora-build .

# Compilation d'un programme dans le conteneur
docker run --platform linux/amd64 -v $(pwd):/app fedora-build gcc -o hello hello.c
```

### Avantages
- Pas besoin d'une machine virtuelle complète
- Isolation de l'environnement de build
- Facilement partageable avec les membres de l'équipe

### Limitations
- Configuration manuelle requise pour chaque architecture
- Processus potentiellement répétitif
- Gestion séparée des artefacts de build

## 2. Docker Buildx pour multi-architecture

### La puissance de Buildx

Buildx est une extension de la CLI Docker qui simplifie considérablement la création d'images multi-architectures.

```bash
# Configuration du builder multi-architecture
docker buildx create --name multi-builder --use

# Vérification
docker buildx ls

# Construction pour plusieurs architectures en même temps
docker buildx build --platform linux/amd64,linux/arm64 -t myapp:latest .

# Construction et publication sur un registre
docker buildx build --platform linux/amd64,linux/arm64 -t username/myapp:latest --push .
```

### Exemple pratique

Créons une application simple compilée pour deux architectures:

```bash
# Dockerfile pour une application Go multi-architecture
cat > Dockerfile <<EOF
FROM golang:1.20 AS builder
WORKDIR /app
COPY . .
RUN CGO_ENABLED=0 go build -o app main.go

FROM alpine:latest
COPY --from=builder /app/app /app
CMD ["/app"]
EOF

# Construction pour plusieurs architectures
docker buildx build --platform linux/amd64,linux/arm64 -t myapp:multi-arch .
```

### Avantages de Buildx
- Construction simultanée pour plusieurs architectures
- Registre d'images intégré pour les artefacts multi-architecture
- Caches partagés entre builds
- Intégration avec CI/CD

## 3. Dev Containers

### Le concept
Dev Containers permet de définir et partager des environnements de développement complets via Docker, directement intégrés dans VS Code.

### Configuration
```json
// .devcontainer/devcontainer.json
{
  "name": "My Project Environment",
  "image": "mcr.microsoft.com/devcontainers/base:ubuntu",
  "features": {
    "ghcr.io/devcontainers/features/node:1": {},
    "ghcr.io/devcontainers/features/python:1": {}
  },
  "customizations": {
    "vscode": {
      "extensions": [
        "dbaeumer.vscode-eslint",
        "ms-python.python"
      ]
    }
  }
}
```

### Workflow d'utilisation
1. Installer l'extension "Dev Containers" dans VS Code
2. Ouvrir un projet avec une configuration devcontainer
3. VS Code propose automatiquement de "Reopen in Container"
4. L'environnement est créé et configuré automatiquement

### Avantages des Dev Containers
- "Works on my machine" devient "Works on all machines"
- Configuration d'environnement versionnée avec le code
- Isolation entre projets
- Support d'architectures multiples intégré
- Expérience de développement complète (debugging, extensions)

## Conclusion

Docker offre une solution polyvalente aux défis de développement sur MacOS:
- **Docker basique**: pour des compilations et tests simples cross-architecture
- **Docker Buildx**: pour la construction et distribution multi-architecture optimisée
- **Dev Containers**: pour des environnements de développement complets et cohérents

Ces outils sont particulièrement précieux dans le contexte de la transition ARM/x86 et permettent aux développeurs MacOS de travailler efficacement sur des projets destinés à diverses plateformes.

## Ressources
- [Docker Desktop pour Mac](https://docs.docker.com/desktop/install/mac-install/)
- [Documentation Buildx](https://docs.docker.com/buildx/working-with-buildx/)
- [VS Code Dev Containers](https://code.visualstudio.com/docs/devcontainers/containers)
