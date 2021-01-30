FROM debian:buster
LABEL owner="bdomitil_ft_server"
WORKDIR /usr/src/app_dir
RUN apt update && apt upgrade -y
RUN apt install php7.3 php7.3-fpm php7.3-mysql php7.3-mbstring php7.3-zip php7.3-gd php7.3-xml php7.3-gettext php7.3-cgi -y
RUN apt install nginx mariadb-server mariadb-client -y
RUN apt install openssl curl -y
COPY ./srcs .
ENTRYPOINT bash script.sh
EXPOSE 443 80
