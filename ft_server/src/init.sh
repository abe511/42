service nginx start
service mysql start
service php7.3-fpm start

echo "create database wordpress;" | mysql -u root --skip-password
echo "grant all privileges on wordpress.* to 'root'@'localhost' with grant option;" | mysql -u root --skip-password
echo "update mysql.user set plugin='' where user='root';" | mysql -u root --skip-password
echo "flush privileges;" | mysql -u root --skip-password

bash