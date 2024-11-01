#include <extism.hpp>
#include <json/json.h>
#include <string>
#include <vector>
#include <fstream>

const extism::Manifest manifest = extism::Manifest::wasmPath("vendor/enhance-ssr.wasm");

const std::string getComponentStr(const std::string& componentName)
{
    const std::ifstream elFile {std::string{"elements/"} + componentName + std::string{".mjs"}};
    std::stringstream elBuf;
    elBuf << elFile.rdbuf();
    return elBuf.str();
}

const Json::Value buildWasmInput(const std::string& markup, const std::vector<std::string> components, const Json::Value& initialState)
{
    // construct JSON object to send to wasm plugin
    Json::Value root{};
    root["markup"] = markup;
    Json::Value elements{};
    for (const std::string& component : components) {
        elements[component] = getComponentStr(component);
    }
    root["elements"] = elements;
    root["initialState"] = initialState;
    return root;
}

const std::string callWasm(Json::Value& input)
{
    static const extism::Plugin plugin{manifest, true};
    auto out {plugin.call("ssr", input.toStyledString())};
    const std::string rawJson {out.string()};

    Json::Value resRoot{};
    Json::CharReader* reader = Json::CharReaderBuilder{}.newCharReader();
    std::string errs{};
    if (!reader->parse(rawJson.c_str(), rawJson.c_str() + rawJson.length(), &resRoot, &errs))
    {
        throw Json::Exception{errs};
    }
    return resRoot["document"].asString();
}


