#!/bin/sh
mkdir /usr/share/
apt install procps -y
ps aux | grep nginx
ps aux | grep mysql
cat default > /etc/nginx/sites-enabled/default
mv site1 site2 phpmyadmin /var/www/html/;
mv /var/www/html/index.nginx-debian.html  /var/www/html/index.html
service nginx start 
service mysql start
echo "CREATE USER 'wordpress'@'localhost' IDENTIFIED BY 'wordpress';" | mysql -u root --skip-password
echo "CREATE DATABASE wordpress;" | mysql -u root --skip-password
echo "GRANT ALL PRIVILEGES ON wordpress.* TO 'wordpress'@'localhost';" | mysql -u root --skip-password
echo "FLUSH PRIVILEGES;" | mysql --skip-password
service php7.3-fpm start
bash