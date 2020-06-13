
/** \brief Validacion de un numero entre un rango minimo y maximo.
 *
 * \param entrada[] char Numero a validar.
 * \param rangoMinimo int Rango minimo para la validacion.
 * \param rangoMaximo int Rango maximo para la validacion.
 * \return int Numero validado.
 *
 */

int validarIntEntreRangos(char entrada[] ,int rangoMinimo,int rangoMaximo);


/** \brief Recibe una cadena para validar que sea numerica.
 *
 * \param entero char* Cadena a validar.
 * \return int Entero validado.
 *
 */
int getInt(char* entero);


/** \brief Analisis de una cadena para determinar que sea numerica.
 *
 * \param char[] Cadena a analizar.
 * \return 0 si la cadena es numerica, 0 si no es numerica.
 *
 */
int validarEntero (char* numeroValidar);

/** \brief Valida que una cadena contenga solo caracteres validos.
 *
 * \param char[] Cadena a validar
 * \return int 1 la cadena es valida, 0 la cadena no es valida.
 *
 */
int validarCadena(char[]);

/** \brief Formatea un nombre al siguiente formato: Matias.
 *
 * \param Nombre
 *
 */
void formatearNombres (char* nombre);

