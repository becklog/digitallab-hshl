This guide provides a comprehensive walkthrough for setting up the digital-lab-environement, a Django application designed for remote testing scenarios. By following these instructions, you will clone the project, set up a virtual environment, install necessary dependencies, and run the server.

## Prerequisites

- Python 3.x installed on your machine
- pip (Python package installer) version corresponding to Python 3
- git (for cloning the repository)
- sudo or administrative access (for Linux/MacOS users) to install certain packages

## Installation Steps

### 1. Clone the Repository

Start by cloning the repository to your local machine. Open a terminal or command prompt and run the following command:
 
`git clone becklog/digitallab-hshl`


### 2. Prepare the Environment

After cloning the repository, create a new folder and copy the "djangoap" folder into it. Navigate into your newly created folder:
 

`cd your-folder`

### 3. Set Up the Virtual Environment

Setting up a virtual environment is crucial for managing the project's dependencies. 
1. Run the following command to install `virtualenv`
2. Next, create a virtual environment named `digital-lab-env`:
3. Activate the virtual environment
#### On MacOS/Linux:

1. `python3 -m pip install --user virtualenv`
2. `python3 -m venv digital-lab-env`
3. `source digital-lab-env/bin/activate`
#### On Windows:

1. `py -m pip install --user virtualenv`
2. `py -m venv digital-lab-env`
3. `.\env\Scripts\activate`

### 4. Install Dependencies

With the virtual environment activated, proceed to install the necessary dependencies. Run the following commands:

 
```
pip install opencv-python django
```

On Linux systems, you may need to install additional libraries to ensure compatibility with `opencv-python`. Run:

 
```
sudo apt-get install libcblas-dev libhdf5-dev libhdf5-serial-dev libatlas-base-dev libjasper-dev libqtgui4 libqt4-test
```

### 5. Run the Server

To run the Django development server:

1. Ensure you are in the root directory of your Django project (where `manage.py` is located).
    
2. Run the server with SSL support by executing:
    

 
`python manage.py runserver 0:8000`

### Accessing the Application

- Open a web browser and navigate to one of the following URLs to access the application:


```bash
localhost:8000
http://<your:ip>:8000/
```

#### Credentials for the admin console are as follows:
- To access the admin console, visit:
`localhost:8000/admin`

- _username_: e.g. admin
- _password_: -> see server.config

```
uwsgi --ini mysite_uwsgi.ini
```
### Additional Resources

- For deploying the application using uWSGI and Nginx, refer to the [uWSGI documentation](https://uwsgi-docs.readthedocs.io/en/latest/tutorials/Django_and_nginx.html).
- To integrate Arduino CLI for projects involving Arduino and Raspberry Pi, visit the [Arduino CLI installation guide](https://arduino.github.io/arduino-cli/0.19/installation/).
- For Raspberry Pi and Arduino serial communication, explore [this tutorial](https://roboticsbackend.com/raspberry-pi-arduino-serial-communication/).

This guide should help you get the digital-lab-environement up and running on your local machine. Remember, this setup is primarily for testing and development purposes. For production deployments, consider securing your application further and using tools like uWSGI in conjunction with Nginx for better performance and security.
