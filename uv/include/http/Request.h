﻿/*
   Copyright © 2017-2020, orcaer@yeah.net  All rights reserved.

   Author: orcaer@yeah.net

   Last modified: 2020-3-30

   Description: https://github.com/wlgq2/uv-cpp
*/

#ifndef UV_HTTP_REQUEST_H
#define UV_HTTP_REQUEST_H

#include <map>
#include "HttpCommon.h"

namespace uv
{
namespace http
{

class Request 
{
public:
    enum Methon
    {
        Get, 
        Post, 
        Head, 
        Put, 
        Delete,
        Connect,
        Options,
        Trace,
        Patch,
        Invalid,
    };
public:
    Request();
    Request(HttpVersion version, Methon methon);

    void swapBody(std::string& str);
    void swapBody(std::string&& str);
    std::string& getBody();
    void appendHead(std::string& key, std::string& value);
    void appendHead(std::string&& key, std::string&& value);
    std::string getHead(std::string& key);
    std::string getHead(std::string&& key);
    void appendUrlParam(std::string& key, std::string& value);
    void appendUrlParam(std::string&& key, std::string&& value);
    std::string getUrlParam(std::string& key);
    std::string getUrlParam(std::string&& key);

    void setVersion(HttpVersion version);
    void setMethon(Methon methon);
    void setPath(std::string&& path);
    void setPath(std::string& path);
    std::string& getPath();
    HttpVersion getVersion();
    Methon getMethon();

    int pack(std::string& data);
    int unpack(std::string& data);

    static std::string MethonToStr(Methon methon);
private:
    Methon methon_; 
    std::string path_;
    std::map <std::string, std::string> urlParms_;
    HttpVersion version_;
    std::map<std::string, std::string> heads_;
    std::string body_;

    void packPathParam(std::string& path);
};

}
}
#endif