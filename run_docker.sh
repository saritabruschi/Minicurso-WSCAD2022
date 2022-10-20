sudo docker build --no-cache -t minicurso .
sudo docker volume create vol_minicurso
sudo docker run -it -v vol_minicurso:/Minicurso_WSCAD_2022 minicurso
