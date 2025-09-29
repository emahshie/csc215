# Inclined Plane Net Force Solution

![image1](image1)

## Problem Restatement

A block of mass **14 kg** starts from rest and slides a distance of **7 m** down an inclined plane making an angle of **40^\circ** with the horizontal.  
The coefficient of sliding friction between the block and the plane is **0.4**.  
Acceleration of gravity: **9.8\ \mathrm{m/s^2}**.  
**Question:** What is the net force on the block along the incline?

---

## Solution

### Step 1: List Given Values

- Mass, $m = 14~\mathrm{kg}$
- Angle of incline, $\theta = 40^\circ$
- Coefficient of friction, $\mu = 0.4$
- Gravitational acceleration, $g = 9.8~\mathrm{m/s^2}$

### Step 2: Forces Acting Along the Incline

1. **Component of gravity down the incline:**
   $$
   F_{\text{gravity, parallel}} = mg\sin\theta
   $$
2. **Friction force up the incline:**
   $$
   F_{\text{friction}} = \mu N
   $$
   Where the normal force $N = mg\cos\theta$, so:
   $$
   F_{\text{friction}} = \mu mg\cos\theta
   $$

3. **Net Force:**
   $$
   F_{\text{net}} = F_{\text{gravity, parallel}} - F_{\text{friction}}
   $$
   $$
   F_{\text{net}} = mg\sin\theta - \mu mg\cos\theta
   $$

### Step 3: Substitute Values

- $\sin(40^\circ) \approx 0.6428$
- $\cos(40^\circ) \approx 0.7660$

Now plug in the numbers:

$$
F_{\text{net}} = (14~\mathrm{kg})(9.8~\mathrm{m/s^2})\sin(40^\circ) - 0.4 \times (14~\mathrm{kg})(9.8~\mathrm{m/s^2})\cos(40^\circ)
$$

Calculate each term:

- $mg = 14 \times 9.8 = 137.2$
- $137.2 \times 0.6428 \approx 88.2$
- $137.2 \times 0.7660 \approx 105.1$
- $0.4 \times 105.1 \approx 42.0$

Subtract:

$$
F_{\text{net}} = 88.2 - 42.0 = \boxed{46.2~\mathrm{N}}
$$

---

## **Final Answer**

$$
\boxed{46.2~\mathrm{N}}
$$

The net force on the block along the incline is **46.2 N**.