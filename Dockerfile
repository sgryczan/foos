FROM armhf/alpine:latest

RUN apk add --no-cache \
    python \
    python-dev \
    py-pip \
    build-base \
    nodejs
RUN pip install pyserial jsonpickle
RUN mkdir /app
COPY . /app
WORKDIR /app/node/
RUN npm config set registry http://registry.npmjs.org
RUN npm install
EXPOSE 3000
CMD ["node", "foos.js"]
