s#!/bin/sh
mkdir /usr/share/
mkdir /tmp/phpMyAdmin
chmod 733 /tmp/phpMyAdmin
mv wordpress/wp-config-sample.php wordpress/wp-config.php
apt install procps -y
ps aux | grep nginx
ps aux | grep mysql
cat default > /etc/nginx/sites-enabled/default
mv site1 site2 phpMyAdmin /var/www/html/;
ln -s /var/www/html/phpMyAdmin /var/www/html/phpmyadmin;
mv /var/www/html/index.nginx-debian.html  /var/www/html/index.html
mv response_page/ /var/www/html/
mv wordpress /var/www/wordpress
chown -R www-data:www-data /var/www/wordpress
service mysql start
echo "CREATE USER 'wordpress'@'localhost' IDENTIFIED BY 'wordpress';" | mysql -u root --skip-password
echo "CREATE DATABASE wordpress;" | mysql -u root --skip-password
echo "GRANT ALL PRIVILEGES ON wordpress.* TO 'wordpress'@'localhost';" | mysql -u root --skip-password
echo "FLUSH PRIVILEGES;" | mysql --skip-password
openssl req -x509 -nodes -days 365 -subj "/C=KR/ST=Korea/L=Seoul/O=innoaca/OU=42seoul/CN=forhjy" -newkey rsa:2048 -keyout /etc/ssl/nginx-selfsigned.key -out /etc/ssl/nginx-selfsigned.crt
service php7.3-fpm start
service nginx start 
bash