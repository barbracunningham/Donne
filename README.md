# Donne

**Lean, fast optimisation and abstraction library for image downloading and processing written in C/C++. Implementing parallel processing, `Donne` provides a high level abstraction interface across `CURL`, `OpenMP`, `mysql-connector` and `OpenCV`.**

**Simple interface bridging HTTP and TCP, using heap memory allocation and parallel threading where appropriate.**


Still in development - This is an open-source project for anybody to contribute to! 

Next deverlopment steps: 

     * Greater range of geometric manipulation functions.
     * Super resolution algorithm support, including single image resolution enhancement.
     * SQL INSERT, UPDATE and JOIN operations.
     * User defined SQL table and column parameters (current default table = 'image_description', column = 'url').
     * Greater OpenMP control, including thread load balance monitoring.
     * Apache Thrift support.






-- Example Operations --


* *Connect to MySQL database:*
  
  `Donne donne_object("101.22.121.334", "my_image_db", "me", "mypass"); //IP, database, user, password`



* *Set parallel thread number (default is machine determined):*

  `donne.override_corethreads(2); //Thread number`



* *Override parallel thread threhold:*

  `donne.override_threshold(400); //Parallel versus serialisation threshold`



* *Pull image URL's:*

  `donne.select_query(0, 244); //Row start, row end`



* *Download each image:*

  `donne.download();`




* *Resize images:*

  `donne.dimensions(3, 3, 0.77, 0.77); //Width, height, scale`






