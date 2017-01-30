# Donne

**Lean, fast optimisation library for image downloading and processing written in C/C++. Implementing parallel processing, `Donne` provides a high level abstraction interface across `CURL`, `OpenMP`, `mysql-connector` and `OpenCV`.**

Still in development.



Simple interface bridging HTTP and TCP, using heap memory allocation where required.




-- Example Operations --


* *Connect to MySQL database:*
  
  `Donne donne_object("101.22.121.334", "my_image_db", "me", "mypass"); //IP, database, user, password`



* *Set parallel thread number:*

  `donne.override_corethreads(2); //Thread number`



* *Override parallel thread threhold:*

  `donne.override_threshold(400); //Parallel versus serialisation threshold`



* *Pull image URL's:*

  `donne.select_query(0, 244); //Row start, row end`



* *Download each image:*

  `donne.download();`




* *Resize images:*

  `donne.dimensions(3, 3, 0.77, 0.77); //Width, height, scale`






