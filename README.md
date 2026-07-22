# C++ HTTP Web Server

A lightweight HTTP web server developed completely from scratch using C++ and Windows Winsock. The project demonstrates networking fundamentals, HTTP request handling, routing, template rendering, and static file serving without using any external web frameworks.

## Features

* HTTP Server using Winsock
* GET Request Handling
* POST Request Handling
* Static File Serving
* HTML Rendering
* CSS Support
* Image Support
* Custom 404 Page
* MIME Type Detection
* Router
* File Manager
* Template Engine
* Dynamic HTML Rendering
* Form Handling

## Project Structure

```
include/
│
├── socket_manager.h
├── router.h
├── file_manager.h
│
src/
│
├── socket_manager.cpp
├── router.cpp
├── file_manager.cpp
│
public/
│
├── index.html
├── style.css
├── images/
├── form.html
├── template.html
├── 404.html
```

## Supported Routes

```
/
```

Returns the home page.

```
/form
```

Displays an HTML form.

```
/submit
```

Processes POST requests.

Unknown routes automatically display the custom 404 page.

## Dynamic Template Example

Template

```
<h1>Welcome {{username}}</h1>
```

Input

```
Ritik
```

Rendered Output

```
Welcome Ritik
```

## Technologies

* C++
* Windows Winsock
* HTTP/1.1
* HTML
* CSS

## Concepts Implemented

* Socket Programming
* HTTP Protocol
* Request Parsing
* Routing
* Static Resource Serving
* Template Rendering
* MIME Types
* File Management

## Future Improvements

* Keep-Alive Connections
* Multithreading
* Cookies
* Sessions
* REST API
* Middleware
* Logging
* Configuration Files

## Author

**Ritik Ranawat**
