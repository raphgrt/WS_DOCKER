# Construction de l'image
```bash
docker build -t firefox .
```

# Compilation du projet dans le conteneur
```bash
xhost +
docker run -it --rm -e DISPLAY=host.docker.internal:0 -v /tmp/.X11-unix:/tmp/.X11-unix firefox
```
