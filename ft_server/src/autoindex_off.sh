sed -i "s/autoindex on/autoindex off/g" /etc/nginx/sites-available/localhost/localhost
echo "autoindex disabled"
service nginx restart