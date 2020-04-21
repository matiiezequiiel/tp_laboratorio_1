/** \brief Muestra menu de opciones.
 *
 * \param char[] Valor de primer operando.
 * \param char[] Valor de segundo operando.
 * \return int   Opcion elegida por el usuario.
 *
 */
int mostrarMenu(char[] ,char[]);


/** \brief  Mostrar resultados una vez realizadas las operaciones.
 *
 * \param char[] Valor de primer operando.
 * \param char[] Valor de segundo operando.
 * \param float  Resultado suma.
 * \param float  Resultado resta.
 * \param float  Resultado division.
 * \param float  Resultado multiplicacion.
 * \param int unsigned longlong Resultado factorial del primer operando.
 * \param int unsigned longlong Resultado factorial del segundo operando.
 * \return void
 *
 */
void mostrarMenuResultados(char[] ,char[],float,float,float,float,unsigned long long int,unsigned long long int);


/** \brief Valida operando y luego devuelve el mismo en formato float.
 *
 * \param char[] Operando a validar.
 * \return float Operando validado y transformado a float.
 *
 */
float getOperando(char[]);


/** \brief Suma 2 operandos.
 *
 * \param operandoUno float Primer operando para la suma.
 * \param operandoDos float Segundo operando para la suma.
 * \return float Resultado de la suma.
 *
 */
float calcularSuma(float operandoUno, float operandoDos);


/** \brief
 *
 * \param operandoUno float Primer operando para la resta.
 * \param operandoDos float Segundo operando para la resta.
 * \return float Resultado de la resta.
 *
 */
float calcularResta(float operandoUno, float operandoDos);


/** \brief
 *
 * \param operandoUno float Primer operando para la multiplicacion.
 * \param operandoDos float Segundo operando para la multiplicacion.
 * \return float Resultado de la multipliacion.
 *
 */
float calcularMultiplicacion(float operandoUno, float operandoDos);


/** \brief
 *
 * \param operandoUno float Primer operando para la division.
 * \param operandoDos float Segundo operando para la division.
 * \return float Resultado de la division.
 *
 */
float calcularDivision(float operandoUno, float operandoDos);


/** \brief Calcula factorial de un operando.
 *
 * \param operando float Operando a calcular.
 * \return unsigned long long int Resultado factorial de operando.
 *
 */
unsigned long long int calcularFactorial(float operando);


/** \brief Valida la entrada de un numero flotante.
 *
 * \param char[] Operando a validar
 * \return int 1 numero invalido, 0 numero valido.
 *
 */
int validarEntrada(char[]);


/** \brief Valida que ambos operandos esten cargados antes de calcular las operaciones.
 *
 * \param char[] Operando uno.
 * \param char[] Operando dos.
 * \return int 1 falta cargar algun operando, 0 ambos numeros cargados.
 *
 */
int validarAmbosOperando(char[],char[]);


