FROM debian:buster

ENV DEBIAN_FRONTEND=noninteractive

# WORKDIR /tmp

RUN apt-get update -y && apt-get upgrade -y && apt-get install apt-utils -y

# INSTALL NGINX 
RUN apt-get install nginx wget nano -y

# INSTALL DB AND PHP
RUN apt-get install mariadb-server php-fpm php-mysql -y

# SETUP LOCALHOST DOMAIN
COPY ./src/localhost /etc/nginx/sites-available/localhost/
RUN ln -s /etc/nginx/sites-available/localhost/localhost /etc/nginx/sites-enabled/

# AUTOINDEX SCRIPTS
COPY ./src/autoindex_on.sh /etc/nginx/sites-available/localhost/
COPY ./src/autoindex_off.sh /etc/nginx/sites-available/localhost/
RUN chmod +x /etc/nginx/sites-available/localhost/autoindex_on.sh
RUN chmod +x /etc/nginx/sites-available/localhost/autoindex_off.sh

# INDEX HTML
COPY ./src/index.html /var/www/localhost/

# PHP INFO https://127.0.0.1/info.php
COPY ./src/info.php /var/www/localhost/info.php

# GENERATE A SELF-SIGNED CERTIFICATE
RUN openssl req -x509 -nodes -days 365 -newkey rsa:4096 -keyout /etc/ssl/private/localhost-self-signed.key -out /etc/ssl/certs/localhost-self-signed.crt -subj "/C=AM/ST=Yerevan/L=Yerevan/O=Convergence Center/OU=42yerevan/CN=localhost"

# ALLOW www-data ACCESS TO WEBSITE CONTENT 
RUN chown -R www-data:www-data /var/www/* && chmod -R 755 /var/www/*

WORKDIR /var/www/localhost

# WORDPRESS
RUN wget https://wordpress.org/latest.tar.gz
RUN tar -xf latest.tar.gz && rm latest.tar.gz
COPY ./src/wp-config.php /var/www/localhost

# PHPMYADMIN
RUN wget https://www.phpmyadmin.net/downloads/phpMyAdmin-latest-english.tar.gz
RUN tar -xf phpMyAdmin-latest-english.tar.gz && rm phpMyAdmin-latest-english.tar.gz
RUN mv phpMyAdmin-*-english phpmyadmin
COPY ./src/config.inc.php /var/www/localhost/phpmyadmin

EXPOSE 80/tcp
EXPOSE 443/tcp

# START SERVICES AND INITIALIZE DB
COPY ./src/init.sh .
CMD bash ./init.sh
