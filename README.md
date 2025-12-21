# posty

C++ service that uses [userver framework](https://github.com/userver-framework/userver).

## Get and Build

1. Clone this repo
2. Open repo folder wih devcontainer (in VSCode or CLion)
3. `make build-{debug/release}`
4. service postgresql start
5. exec `./scripts/start-service`

## Makefile

`PRESET` is either `debug`, `release`

* `make cmake-PRESET` - run cmake configure, update cmake options and source file lists
* `make build-PRESET` - build the service
* `make test-PRESET` - build the service and run all tests
* `make start-PRESET` - build the service, start it in testsuite environment and leave it running
* `make install-PRESET` - build the service and install it in directory set in environment `PREFIX`
* `make` or `make all` - build and run all tests in `debug` and `release` modes
* `make format` - reformat all C++ and Python sources
* `make dist-clean` - clean build files and cmake cache
* `make docker-COMMAND` - run `make COMMAND` in docker environment
* `make docker-clean-data` - stop docker containers

## For development

1. change password for users (root, postgres)
2. start and create user with db
```bash
sudo service postgres start
psql -h localhost -U postgres -W -f ./postgresql/createdb.sql
```
3. create tables and funcs
```bash
psql -h localhost -U posty_user -W -d posty_db-1 -f ./postgresql/schemas/db-1.sql
```

## License

The original template is distributed under the [Apache-2.0 License](https://github.com/userver-framework/userver/blob/develop/LICENSE)
and [CLA](https://github.com/userver-framework/userver/blob/develop/CONTRIBUTING.md). Services based on the template may change
the license and CLA.