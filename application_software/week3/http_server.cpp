#include "http_server.hh"

#include <vector>

#include <sys/stat.h>
#include <string.h>
#include <fstream>
#include <sstream>

vector<string> split(const string &s, char delim) {
  vector<string> elems;

  stringstream ss(s);
  string item;

  while (getline(ss, item, delim)) {
    if (!item.empty())
      elems.push_back(item);
  }

  return elems;
}

HTTP_Request::HTTP_Request(string request) {
  vector<string> lines = split(request, '\n');
  vector<string> first_line = split(lines[0], ' ');

  this->HTTP_version = "1.0"; // We'll be using 1.0 irrespective of the request
  /*
   TODO : extract the request method and URL from first_line here
  */
  // int i;
  // for(i = 0; i < first_line.size(); i++) {
  //   if(first_line[i] == ' ') {
  //     break;
  //   }
  //   this->method[i] = first_line[i];
  // }

  // i ++;
  // for(int t = 0;i < first_line.size();i++,t++) {
  //   if(first_line[i] == ' ') {
  //     break;
  //   }
  //   this->url[t] = first_line[i];
  // }
  this->method = first_line[0];
  this->url = first_line[1];
  



  if (this->method != "GET") {
    cerr << "Method '" << this->method << "' not supported" << endl;
    exit(1);
  }
}



HTTP_Response *handle_request(string req) {
  HTTP_Request *request = new HTTP_Request(req);

  HTTP_Response *response = new HTTP_Response();

  string url = string("html_files") + request->url;

  response->HTTP_version = "1.0";

  struct stat sb;
  if (stat(url.c_str(), &sb) == 0) // requested path exists
  {
    response->status_code = "200";
    response->status_text = "OK";
    response->content_type = "text/html";

    string body;

    if (S_ISDIR(sb.st_mode)) {
      /*
      In this case, requested path is a directory.
      TODO : find the index.html file in that directory (modify the url
      accordingly)
      */
      url.append("/index.html");

    }
    ifstream file;
    file.open(url,ios::in);
    file.seekg(0,ios::end);
    int filesize = file.tellg();
    if(file.is_open()) {
      string line;
      while(getline(file,line)) {
        response->body.append(line);
      }
    }
    file.close();
    stringstream ss;
    ss<<filesize;
    string s;
    ss>>s;

    /*
    TODO : open the file and read its contents
    */
    response->content_length = s;
    response->connection = "Closed";
    /*
    TODO : set the remaining fields of response appropriately
    */


  }

  else {
    response->status_code = "404";
    response->status_text = "Not Found";
    /*
    TODO : set the remaining fields of response appropriately
    */
  }

  delete request;

  return response;
}

string HTTP_Response::get_string() {
  /*
  TODO : implement this function
  */ 

  string s;
  s.append(this->status_code);
  s.append(this->status_text);
  s.append(this->content_type);
  s.append(this->body);
  s.append(this->content_length);
  s.append(this->connection);
 return s;
}
