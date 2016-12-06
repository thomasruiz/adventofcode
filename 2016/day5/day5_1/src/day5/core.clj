(ns day5.core (:gen-class))

(import 'java.security.MessageDigest
        'java.math.BigInteger)

(defn md5 [s]
  (let [algorithm (MessageDigest/getInstance "MD5")
        size (* 2 (.getDigestLength algorithm))
        raw (.digest algorithm (.getBytes s))
        sig (.toString (BigInteger. 1 raw) 16)
        padding (apply str (repeat (- size (count sig)) "0"))]
    (str padding sig)))

(def input (slurp "../day5_input.txt"))

(defn -main
  [& args]
  (loop [password ""
         hash (md5 (str input "0"))
         i 0]
    (if (= (count password) 8)
      (println password)
      (recur
        (if-not (= (subs hash 0 5) "00000")
          password
          (str password (nth hash 5)))
        (md5 (str input (str (+ i 1))))
        (+ i 1)))))
