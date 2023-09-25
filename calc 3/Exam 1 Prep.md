`` This covers the entirety of 10.1 to 10.9, with the exception of 10.6 which is not covered in the first exam ``
# Magnitude
- $|\vec a| = \sqrt{a_1^2 + a_2^2 + a_3^2}$
- Also denoted by $||\vec a||$
- This is simply the distance from the origin to the point $a$
- Can be modified to find the distance between two vectors

# Unit Vector
- $\vec a = \frac{\vec a}{|\vec a|}$
- A unit vector is a vector with a magnitude of 1
- You can get two unit vectors by including the negative value of the original vector
  - $\vec a = \frac{\vec a}{|\vec a|}$ and $\vec a = \frac{-\vec a}{|\vec a|}$
- To convert a vector into a unit vector, divide the vector by its magnitude

# Dot Product
- $\vec a \cdot \vec b = <a_1b_1 + a_2b_2 + a_3b_3>$
- Used to multiple two vectors
- Can be used to find the angle between two vectors
- $\vec a \cdot \vec b = |\vec a||\vec b|cos(\theta)$
  - This assumes that $\theta$ is the angle between the two vectors
  - Alternatively written as $cos(\theta) = \frac{\vec a \cdot \vec b}{|\vec a||\vec b|}$
- The vectors $a$ and $b$ are orthogonal if $a \cdot b = 0$ (aka orthogonal)
  - $a \cdot b > 0$ if the angle between the two vectors is acute
  - $a \cdot b < 0$ if the angle between the two vectors is obtuse

# Cross Product
- $\vec a \times \vec b = <a_2b_3 - a_3b_2, a_3b_1 - a_1b_3, a_1b_2 - a_2b_1>$
- Given $\vec a = <a_1, a_2, a_3>$ and $\vec b = <b_1, b_2, b_3>$
- $\vec a \times \vec b = \begin{vmatrix} \vec i & \vec j & \vec k \\ a_1 & a_2 & a_3 \\ b_1 & b_2 & b_3 \end{vmatrix} = \begin{vmatrix} a_2 & a_3 \\ b_2 & b_3\end{vmatrix}\vec i - \begin{vmatrix} a_1 & a_3 \\ b_1 & b_3\end{vmatrix}\vec j + \begin{vmatrix} a_1 & a_2 \\ b_1 & b_2\end{vmatrix}\vec k =\\ <a_2 b_3 - a_3 b_2 \bold , a_3 b_1 - a_1 b_3 \bold , a_1 b_2 - a_2 b_1>$
- Used to find the vector orthogonal to two vectors ($\vec a \times \vec b$ is always orthogonal to $\vec a$ and $\vec b$)
- The magnitude of the cross product is equal to the area of the parallelogram formed by the two vectors

# Scalar Projection
- Scalar projection where $\vec a$ is the vector being projected onto $\vec b$
  - $proj_{\vec a}\vec b = \frac{\vec a \cdot \vec b}{|\vec a|} = |\vec b|cos(\theta)$

# Vector Projection
- Vector projection where $\vec a$ is the vector being projected onto and $\vec b$
- $comp_{\vec a} \vec b = \frac{\vec a \cdot \vec b}{| \vec a|}$

# Work
- $W = \vec F \cdot \vec d$
- Work is the dot product of force and displacement
  - $W = |\vec F||\vec d|cos(\theta)$

# Equation of lines and planes
## Lines
  - Straight lines can be represented once we have:
    - The position vector of the initial point
    - The direction vector of the line
    - The equation can be represented as
      - $\vec r = \vec r_0 + t\vec v$
      - $\vec r_0$ is the position vector of the initial point
      - $\vec v$ is the direction vector of the line
      - $t$ is a scalar (just a variable like how x is for 2d lines)
      ## Parametric Equations
      - Parametric Equation of the line L passing through the point $P_0(x_0, y_0, z_0)$ and parallel to the vector $\vec v = <a, b, c>$
        - $x = x_0 + at$
        - $y = y_0 + bt$
        - $z = z_0 + ct$
      - Solving for Symmetric equations of L assuming $a \ne 0, b \ne 0, c \ne 0$
        - $t = \frac{x - x_0}{a} = \frac{y - y_0}{b} = \frac{z - z_0}{c}$
## Planes
- Planes can be represented once we have:
  - The coordinates of a point on the plane
  - A normal vector $\vec n = <a, b, c>$ that is orthogonal to the plane
    - $\vec n = \vec {ab} \times \vec {ac}$
  - The equation can be represented as:
    - $\vec n \cdot (\vec r - \vec r_0) = 0$
      - Simplifes to $ax + by + cz = d$ or $a(x-x_0)+b(y-y_0)+c(z-z_0)=0$
        - $d = ax_0 + by_0 + cz_0$
- To find the angle between two planes, find the angle between their normal vectors
  - $cos(\theta) = \frac{|\vec n_1 \cdot \vec n_2|}{||\vec n_1|| \ ||\vec n_2||}$
  - The absolute value is used to ensure that the angle is acute

# Graph of a Continuous Vector-Valued Function
- Limits
  - if $\vec r(t) = f(t)\vec i + g(t)\vec j + h(t)\vec k$, then $\lim_{t \to a} \vec r(t) = (\lim_{t \to a} f(t))\vec i + (\lim_{t \to a} g(t))\vec j + (\lim_{t \to a} h(t))\vec k$
- Derivatives of Vector-Valued Functions
  - $\vec r'(t) = \lim_{h \to 0} \frac{\vec r(t+h) - \vec r(t)}{h}$, provided the limit exists
- Graphical Interpretation of Derivatives
  - $\vec r'(t)$ is a tangent vector to the curve $\vec r(t)$ at the point $\vec r(t)$
- Unit Tangent Vector
  - $\vec T(t) = \frac{\vec r'(t)}{||\vec r'(t)||}$
- Theorem
  - If $\vec r(t)$ = f(t)$\vec i$ + g(t)$\vec j$ + h(t)$\vec k$
 is a differentiable vector-valued function, then $\vec r'(t)$ = f'(t)$\vec i$ + g'(t)$\vec j$ + h'(t)$\vec k$
- Integration of Vector-Valued Functions
  - $\int_{a}^{b} \vec r(t) dt = (\int_{a}^{b} f(t) dt) \vec i + (\int_{a}^{b} g(t) dt) \vec j + (\int_{a}^{b} h(t) dt) \vec k$
  - $\int \vec r(t)dt = (\int f(t) dt) \vec i + (\int g(t) dt) \vec j + (\int h(t) dt) \vec k$
    - Where $\vec C = <C_1, C_2, C_3>$ is a constant vector

# Arc Length
- In Calc 2, we learned that the arc length of a curve $y = f(x)$ from $x = a$ to $x = b$ is given by
  - $L = \int_{a}^{b} \sqrt {[f'(t)]^2 + [g'(t)]^2} dt$
- In Calc 3, we will learn that the arc length of a curve $\vec r(t) = f(t)\vec i + g(t)\vec j + h(t)\vec k$ from $t = a$ to $t = b$ is given by
  - $L = \int_{a}^{b} \sqrt {[f'(t)]^2 + [g'(t)]^2 + [h'(t)]^2} dt$
  - Formula above simplifes into $L = \int_{a}^{b} ||\vec r'(t)|| dt$
- Let C be a smooth curve in $R^3$ with parametrization $\vec r(t)$. Provided that $\vec T'(t) \ne 0$, the principal unit normal vector $\vec N(t)$ is given by
  - $\vec N(t) = \frac{\vec T'(t)}{||\vec T'(t)||}$
- A unit vector that is perpendicular to both $\vec T(t)$ and $\vec N(t)$ is called the binormal vector $\vec B(t)$
  - $\vec B(t) = \vec T(t) \times \vec N(t)$

# Motion in Space: Velocity and Acceleration
- Velocity
  - $\vec v(t) = \vec r'(t)$
- Acceleration
  - $\vec a(t) = \vec v'(t) = \vec r''(t)$
- Speed
  - $s(t) = ||\vec v(t)||$
- You can freely integrate and differentiate vectors
  - $\vec r(t) = \int \vec v(t) dt$
  - $\vec v(t) = \frac{d}{dt} \vec r(t)$
  - $\vec v(t) = \int \vec a(t) dt$
  - $\vec a(t) = \frac{d}{dt} \vec v(t)$
- $\vec r(t) = (||\vec v_0||cos \alpha)t\vec i + ((||\vec v_0||sin \alpha)t - \frac{1}{2}gt^2)\vec j$
  - The $\vec r(t) = (||\vec v_0||cos \alpha)t\vec i$ is the x(t) component and the $\vec r(t) = ((||\vec v_0||sin \alpha)t - \frac{1}{2}gt^2)\vec j$ is the y(t) component
  - You can obtain the maximum height in several ways such as
    -  Solving for $r(t) = 0$ and finding the t value. Half the t value and that is the time when height is max
    -  You can use algebra you learned previously to find the max height

# Miscellaneous
- If $\theta$ is the angle between two vectors $\vec a$ and $\vec b$, where $0 \le \theta \le \pi$
  - $| \vec a \times \vec b | = |\vec a||\vec b|sin(\theta)$