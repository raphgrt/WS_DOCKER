# Construction de l'image
```bash
docker build -t my-app .
```

# Compilation du projet dans le conteneur
```bash
xhost +
docker run --rm my-app
```
