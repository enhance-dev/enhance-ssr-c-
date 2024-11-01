#include "include/httplib.h"
#include "lib/wasm.h"
#include <exception>
#include <extism.hpp>
#include <json/json.h>
#include <string>

int main()
{
    httplib::Server server{};

    server.Get("/", [](const httplib::Request& req, httplib::Response& res)
    {
        const std::string markup {"<my-header>Hello World</my-header>"};
        try
        {
            Json::Value pluginInput {buildWasmInput(markup, {"my-header"}, Json::Value{})};
            res.set_content(callWasm(pluginInput), "text/html");
        }
        catch (const std::exception& e)
        {
            res.status = 500;
            res.set_content(e.what(), "text/plain");
        }
    });

    server.listen("0.0.0.0", 3456);
}
