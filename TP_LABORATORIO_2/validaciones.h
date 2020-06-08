/** \brief Muestra menu de ABM
 *
 * \param void
 * \return int Opcion elegida por el usuario.
 *
 */
int mostrarMenu(void);



/** \brief Valida que una cadena contenga solo caracteres validos.
 *
 * \param char[] Cadena a validar
 * \return int 1 la cadena es valida, 0 la cadena no es valida.
 *
 */
int validarCadena(char[]);



/** \brief Ingresa una cadena con la opcion ingresada del usuario para su posterior validacion.
 *
 * \param char[] Cadena ingresada por el usuario.
 * \return float Numero validado.
 *
 */
float getFloat(char[]);


/** \brief Analisis de una cadena para determinar que sea flotante.
 *
 * \param char[] Cadena a analizar.
 * \return int 0 si la cadena es numero flotante, 0 si no es numerica.
 *
 */
int validarFloat(char[]);



/** \brief Ingresa una cadena con la opcion ingresada del usuario para su posterior validacion.
 *
 * \param char[] Cadena ingresada por el usuario.
 * \return int Numero validado.
 *
 */
int getInt(char[]);



/** \brief Analisis de una cadena para determinar que sea numerica.
 *
 * \param char[] Cadena a analizar.
 * \return 0 si la cadena es numerica, 0 si no es numerica.
 *
 */
int validarEntero (char[]);



/** \brief Validacion de un numero entre un rango minimo y maximo.
 *
 * \param entrada[] char Numero a validar.
 * \param rangoMinimo int Rango minimo para la validacion.
 * \param rangoMaximo int Rango maximo para la validacion.
 * \return int Numero validado.
 *
 */
int validarIntEntreRangos(char[],int,int);



/** \brief Formatea el nombre
 *
 * \param Cadena a formatear
 * \return
 *
 */
void formatearNombres (char* nombre);

