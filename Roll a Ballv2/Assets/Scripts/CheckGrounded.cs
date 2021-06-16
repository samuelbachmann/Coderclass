using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CheckGrounded : MonoBehaviour
{
  
    public GameObject Player;
    void Start()
    {
        Player = gameObject;
    }

    private void OnCollisionEnter(Collision collision)
    {
        if (collision.collider.tag == "Ground")
        {
            Player.GetComponent<PlayerController>().isGrounded = true;
        }
    }

    private void OnCollisionExit(Collision collision)
    {
        if (collision.collider.tag == "Ground")
        {
            Player.GetComponent<PlayerController>().isGrounded = false;
        }
    }
}
