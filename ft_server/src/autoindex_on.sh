sed -i "s/autoindex off/autoindex on/g" /etc/nginx/sites-available/localhost/localhost
echo "autoindex enabled"
service nginx restart