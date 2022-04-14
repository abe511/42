
build:
	docker build -t serv --rm .
run:
	docker run --name server -it -p 80:80 -p 443:443 serv
it:
	docker start server
	docker exec -it server bash
clean:
	docker stop server
	docker rm server
fclean:
	docker stop server || true
	docker rm server || true
	docker rmi serv
